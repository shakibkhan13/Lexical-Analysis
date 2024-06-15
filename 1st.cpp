#include<bits/stdc++.h>
using namespace std;
bool Operator(char ch){
    return(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='>'||ch=='<'||ch=='!'||ch=='&'||ch=='|');
}
bool Punctuation(char ch){
    return(ch==';'||ch==','||ch==':'||ch=='('||ch==')'||ch=='{'||ch=='}'||ch=='['||ch==']');
}

bool Digit(char ch){
    return(ch>='0'&&ch<='9');
}
bool Letter(char ch){
    return(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}
bool Keyword(string str){
    vector<string>keywords ={"int","float","char","double","if","else","for","while","do","break","continue","return","switch","case","default", "struct", "union", "enum", "typedef", "sizeof", "const", "static", "extern", "auto", "register", "goto"};
    for(string keyword : keywords){
        if(keyword==str){
            return true;
        }
    }
    return false;
}
vector<string>tokenize(string line){
    vector<string> tokens;
    string currentToken="";
    for(int i=0;i<line.size();i++){
        char ch=line[i];
        if(isspace(ch)){
            if(currentToken != ""){
                tokens.push_back(currentToken);
                currentToken="";
            }
        }else if(Operator(ch)||Punctuation(ch)){
            if(currentToken!=""){
                tokens.push_back(currentToken);
                currentToken = "";
            }
            tokens.push_back(string(1,ch));
        } else{
            currentToken+=ch;
        }
    }
    if(currentToken!=""){
        tokens.push_back(currentToken);
    }
    return tokens;
}

int main(){
    string line;
    cout<<"Enter a line of code: ";
    getline(cin,line);
    vector<string>tokens=tokenize(line);

    vector<string>keywords,identifiers,operators,constants,punctuations;

    for(string token : tokens){
        if(Keyword(token)){
            keywords.push_back(token);
        }else if(Letter(token[0])||(token[0]=='_'&&token.size()>1)){
            identifiers.push_back(token);
        }else if(Operator(token[0])){
            operators.push_back(token);
        }else if(Digit(token[0])){
            constants.push_back(token);
        }else if(Punctuation(token[0])){
            punctuations.push_back(token);
        }else{
            cout<<"Unknown token: "<<token<<endl;
        }
    }
    cout<<"Keywords("<<keywords.size()<<"): ";
    for(size_t i=0; i<keywords.size(); i++){
        cout<<keywords[i];
        if(i<keywords.size()-1){
            cout<<", ";
        }
    }
    cout<<endl;
    cout<<"Identifiers("<<identifiers.size()<<"): ";
    for(size_t i=0;i<identifiers.size(); i++){
        cout<<identifiers[i];
        if(i<identifiers.size()- 1){
            cout<<", ";
        }
    }
    cout<<endl;
    cout<<"Operators("<<operators.size()<<"): ";
    for(size_t i=0; i<operators.size(); i++){
        cout<<operators[i];
        if(i<operators.size()-1){
            cout<<", ";
        }
    }
    cout<<endl;

    cout<<"Constants("<<constants.size()<< "): ";
    for(size_t i=0; i<constants.size(); i++){
        cout<<constants[i];
        if(i<constants.size()-1){
            cout<<", ";
        }
    }
    cout<<endl;

    cout<<"Punctuations ("<<punctuations.size()<< "): ";
    for(size_t i=0; i< punctuations.size(); i++){
        cout<<punctuations[i];
        if(i<punctuations.size()- 1){
            cout<<", ";
        }
    }
    cout<<endl;

    return 0;
}

