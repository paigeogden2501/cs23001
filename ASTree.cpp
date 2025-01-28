//
//  ASTree.cpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2024 Kent State University. All rights reserved.
//  Spring 2024
//  srcML 1.0
//
//  Modified by:
//  Paige Ogden
//
// line to run:
// make profiler
// ./profiler sort.cpp.xml sort_lib.cpp.xml
// ./profiler simple.cpp.xml
// valgrind ./profiler simple.cpp.xml

#include "ASTree.hpp"


// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    if (actual.tree)
        tree   = new AST(*(actual.tree));
    else
        tree = 0;
}

// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}

// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}

//  Adds in the includes and profile object declarations
//
void srcML::mainHeader(const std::vector<std::string>& profileName,
                       const std::vector<std::string>& fileName    ) {
    tree->mainHeader(profileName, fileName);
}

//  Adds in the includes and declares profile object declarations
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}

// Adds in the report to the main
//
void srcML::mainReport(const std::vector<std::string>& profileName) {
        tree->mainReport(profileName);
}

///  Inserts a profile.count() into each function body.
//
void srcML::functionCount(const std::string& profileName) {
    tree->functionCount(profileName);
}

// Inserts a profile.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) {
    tree->lineCount(profileName);
}

    

//
//AST::
//


// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


// Destructor for AST
//
AST::~AST() {
    //TODO: IMPLEMENT
    //Recursively traverse tree and delete from bottom up

    // make an iterator to go through the tree
    // .begin makes it start from left side of the root
    // (left most root)
    std::list<AST*>::const_iterator i = child.begin();
    // while the child is not empty and it is not the end
    // .end makes it end at right most root
    while(!child.empty() && i != child.end()) {
        // delete 
        delete *i;
        ++i;
    }
}


// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    //TODO: IMPLEMENT
    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.

    // setting the mem variables equal
    // "copying them"
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.closeTag;
    text = actual.text;

    // starting from the left most node of the actual tree
    std::list<AST*>::const_iterator i = actual.child.begin();
    // while the iterator is not the end
    while(i != actual.child.end()) {
        // copy the node to this
        // two ** becuase it is a pointer pointing to a pointer
        // and has to be dereferenced twice
        child.push_back(new AST(**i));
        ++i;
    }
}


// Constant time swap for AST
//
void AST::swap(AST& rhs) {
    //TODO: IMPLEMENT
    //Swap all the top level childern (pointers to AST)

    // mem var nodetype swap:
    nodes temp1;
    temp1 = nodeType;
    nodeType = rhs.nodeType;
    rhs.nodeType = temp1;

    // mem var text swap:
    std::string temp2;
    temp2 = text;
    text = rhs.text;
    rhs.text = temp2;

    // mem var tag swap:
    temp2 = tag;
    tag = rhs.tag;
    rhs.tag = temp2;

    // mem var closetag swap:
    temp2 = closeTag;
    closeTag = rhs.closeTag;
    rhs.closeTag = temp2;

    // swaps the children
    child.swap(rhs.child);
}

/// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


// REQUIRES: this->nodetype == category && tagName is valid srcML tag
// ENSURES: RETVAL == this->child[i] where this->child[i]->tag == tagName
//
// IMPORTANT for milestone 2 and 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


// REQUIRES: this->tag == "name"
// Returns the full name of a <name> node
//  There are two types of names in srcML.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from <name> AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


//  Adds above the main, in the main file:
//  1. #include "profile.hpp"
//  2. All needed profile object declarations
//      example: profile foo_cpp("foo.cpp");
//
void AST::mainHeader(const std::vector<std::string>& profileName,
                     const std::vector<std::string>& fileName     ) {

    //TODO: IMPLEMENT
    //Skip down a couple lines or find main and put it before it
    //Add a node with #include "profile.hpp"
    //For each file profile name, add a node with a profile
    //   declaration "profile foo_cpp("foo.cpp");"

    // makes the variable for the include path for the header
    std::string profileString = "#include \"profile.hpp\"";
    
    // makes iterator, of a doubly linked list, of the Tree
    std::list<AST*>::iterator object = child.begin();

    // while the iterator * is not equal to a func
    while((*object)->tag != "function") {
        ++object;
    }

    // inserts the include line before the function
    child.insert(object, new AST(token, profileString));

    // makes const iterator, for a vector of strings
    // always points to the same pointer
    std::vector<std::string>::const_iterator itr1 = profileName.begin();
    std::vector<std::string>::const_iterator itr2 = fileName.begin();

    // while it has not reached the end of the profileName
    while(itr1 != profileName.end()) {
        profileString = "\nprofile " + (*itr1) + "(\"" + (*itr2) + "\")" + ";";

        // inserts more into the child node w the profile declaration
        child.insert(object, new AST(token, profileString));

        ++itr1;
        ++itr2;
    }
    child.insert(object, new AST(token, "\n\n"));
}


//  Adds in each file (except main file):
//  1. #include "profile.hpp"
//  2. All needed external profile object declarations
//      example: extern profile thisfile_cpp;
//
void AST::fileHeader(const std::string& profileName) {

    //TODO: IMPLEMENT
    //Skip down a couple lines or find first function and put it before it
    //Add #include "profile.hpp"
    //Add in the external declaration for that file "extern profile foo_cpp;"

    // makes iterator, of a doubly linked list, of the Tree
    std::list<AST*>::iterator object = child.begin();

    // while the iterator * is not equal to a func
    while((*object)->tag != "function") {
        ++object;
    }

    std::string fileCpp = profileName;

    // changes the '_' to a dot .
    for(size_t j = 0; j != fileCpp.length(); ++j) {
        if (fileCpp[j] == '_') {
            fileCpp[j] = '.';
        }
    }


    // makes the variable for the include path for the header
    std::string profileString = "#include \"profile.hpp\"";

    // redefine profile string
    profileString = profileString + "\nextern profile " + profileName + ";\n\n";
    // inserts more into the child node w the profile declaration
    child.insert(object, new AST(token, profileString));
}


// Adds in the report to the main file
// Assumes only one return in the main
//
void AST::mainReport(const std::vector<std::string>& profileName) {
    
    //TODO: IMPLEMENT
    //Find the function with name of "main" in the file
    // -Get the "block" node of this function
    // -Set an iterator to the child.end() of "block"
    // -Decrement it once (to skip the "}")
    // -Search backwards for a "return" tag
    // -Insert the report statements before the return

    std::list<AST*>::iterator itr = child.begin();

    while(itr != child.end()) {
        // if we're in the main function
        if  ((*itr)->tag == "function") {
            AST* name = (*itr)->getChild("name");

            if((name)->getName() == "main") {
                // getting the main code block
                AST *blockPtr = (*itr)->getChild("block");
                // getting stuff in the block
                AST *blockContentPtr = (blockPtr->getChild("block_content"));
                AST *returnPtr = (blockContentPtr)->getChild("return");
                // setting an iterator to the main block
                std::list<AST*>::iterator blockItr = (returnPtr)->child.begin();

                std::string outputCode;
                for(std::vector<std::string>::const_iterator i = profileName.begin();
                    i != profileName.end(); ++i) {
                    outputCode = outputCode + ("std::cout<< " + (*i) + " <<std::endl;\n" + "    ");
                }

                AST *output = new AST(token, outputCode);
                returnPtr->child.insert(blockItr, output);
            }
        }

        ++itr;
    }
}


// Adds a node to the function block to count the times each function
//  is executed
//  Assumes no nested functions
//
void AST::functionCount(const std::string& profileName) {
    
    //TODO: IMPLEMENT
    // for each child in the "unit"
    //     if child is a function, constructor, destructor
    //        Find the function name (use AST::getName())
    //        Find <block>, then find <block_content>
    //        Insert the count as first child in <block_content>
    //        Example: main1_cpp.count(__LINE__, "main");

    // setting an itr to the beginning of a child
    std::list<AST*>::iterator itr = child.begin();
    // while the itr is not the end...
    while(itr != child.end()) {
        // if child is a function, constructor, destructor
        if( ((*itr)->tag == "function") || ((*itr)->tag == "constructor") || ((*itr)->tag == "destructor")) {
            // finding block
            AST *block = (*itr)->getChild("block");
            std::string functionName, countCode;
            // getting name
            AST *name = (*itr)->getChild("name");
            AST *nameChild = name->child.front();
            functionName = nameChild->text;
            countCode = " " + profileName + ".count(__LINE__, \"" + functionName + "\"); \n";
            AST *count = new AST(token);
            count->text = countCode;
            std::list<AST*>::iterator blockItr = block->child.begin();
            // finding the beginning of the block
            while((*blockItr)->text != "{") {
                ++blockItr;
            }
            ++blockItr;
            // Insert the count as first child in <block_content>
            block->child.insert(blockItr,count);
        }
        ++itr;
    }

}


// Adds in a node to count the number of times each statement is executed
//   Do not count breaks, returns, throw, declarations, etc.
//   Assumes all construts (for, while, if) have an explicit block { }
//
void AST::lineCount(const std::string& profileName) {
    
    //TODO: IMPLEMENT
    // Recursively check for expr_stmt within all category nodes <block>
    // Very similar to AST::print
    // For each child:
    //   If it is a category node
    //       If it is a expr_stmt insert a count after it
    //          Example: foo_cpp.count(__LINE__);
    //       Else call lineCount if not a stop tag  See isStopTag()
    //   Else (token or whitespace) do nothing

    // itr at the beginning of the child
    std::list<AST*>::const_iterator i = child.begin();
    // while not the end of child...
    while(i != child.end()) {
        // if category node
        if((*i)->nodeType == category) {
            // if expr_stmt
            if((*i)->tag == "expr_stmt") {
                // insert a count
                child.insert(++i, new AST(token, " " + profileName + ".count(__LINE__);"));
            }
            // if condition node
            else if ((*i)->tag == "condition") {
                // insert
                child.insert((*i)->getChild("expr")->child.begin(), new AST(token, profileName + ".count(__LINE__), "));
            }
            // else call lineCount if not a stop tag
            else if (!isStopTag((*i)->tag)) {
                (*i)->lineCount(profileName);
            }
        }

        ++i;
    }
}

// Returns TRUE if the tag (syntactic category) is not to be profiled
//
// IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "condition"             ) return true; //Remove for challenge
    if (tag == "type"                  ) return true;
    if (tag == "name"                  ) return true;
    if (tag == "return"                ) return true;
    if (tag == "break"                 ) return true;
    if (tag == "continue"              ) return true;
    if (tag == "parameter_list"        ) return true;
    if (tag == "decl_stmt"             ) return true;
    if (tag == "argument_list"         ) return true;
    if (tag == "init"                  ) return true;
    if (tag == "cpp:include"           ) return true;
    if (tag == "macro"                 ) return true;
    if (tag == "comment type=\"block\"") return true;
    if (tag == "comment type=\"line\"" ) return true;
    return false;
}


// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node, print it
        else
            (*i)->print(out);    //Category node, recursive call
    }
    return out;
}


// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}



// Utilities for AST::read()

// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">"); }
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<"); }
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&"); }
    return s;
}

// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

