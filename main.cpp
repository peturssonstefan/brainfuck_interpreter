#include <iostream>
#include <vector>

using byte = unsigned char; 

bool isAlreadyAdded(std::vector<int> loopP, int insP){
  if(loopP.size() == 0){
    return false; 
  }
  return loopP[loopP.size()-1] == insP; 
}

void readInput(const std::string &input, byte* buffer, int &inpP, int &insP, int bufP){
    buffer[bufP] = input[inpP]; 
    inpP++; 
    insP++; 
}

int findNextClosingBracket(int insP, const std::string code){
  int openBracketsMet = 0; 
  int closedBracketsMet = 0; 
  for(int i = insP+1; i < code.length(); i++){
    if(code[i] == '['){
      openBracketsMet++; 
    }
    else if(code[i] == ']'){
      closedBracketsMet++; 
      if(closedBracketsMet > openBracketsMet){
        return i+1; //assume return here. Otherwise error in input code. 
      }
    }
    else{}
  }

  return -1; 
}

void handleLoopStart(const std::string &code, byte *buffer, std::vector<int> &loopP, int &insP, int bufP){
    if(buffer[bufP] == 0){
        insP = findNextClosingBracket(insP, code); 
    }
    else if(loopP.size() == 0 || !isAlreadyAdded(loopP, insP)){
        loopP.push_back(insP); 
        insP++; 
    }
    else {
        insP++; 
    }
}

void handleLoopClose(byte *buffer, std::vector<int> &loopP, int &insP, int bufP){
    if(buffer[bufP] == 0){
        insP++; 
        loopP.pop_back(); 
    }
    else {
        insP = loopP[loopP.size() - 1]; 
    }
}

std::string brainLuck(const std::string &code, const std::string &input) {
  
  std::string res; 
  int bufP = 0; //buff pointer
  int inpP = 0; //input pointer
  int insP = 0; //instruction pointer
  std::vector<int> loopP; 
  byte buffer[5000] = { 0 }; //Assuming 5K is enough. 
  
  while(insP < code.length()){
    auto instruction = code[insP]; 
    
    switch(instruction){
        case ',':
            readInput(input, buffer, inpP, insP, bufP); 
            break; 
        case '+': 
            buffer[bufP]++; 
            insP++; 
            break;
        case '-': 
            buffer[bufP]--; 
            insP++; 
            break; 
        case '[':
            handleLoopStart(code, buffer, loopP, insP, bufP); 
            break; 
        case ']':
            handleLoopClose(buffer, loopP, insP, bufP); 
            break; 
        case '.':
            res += buffer[bufP]; 
            insP++;
            break;
        case '>': 
            bufP++; 
            insP++;
            break; 
        case '<': 
            bufP--; 
            insP++; 
            break; 
        default: 
            exit(-1); 
    }
  }
    
  return res; 
}

int main(int argc, char *argv[]){
    std::string program(argv[1]); 
    std::string input; 
    if(argv[2]){
        input = argv[2]; 
    }
    std::cout << brainLuck(program, input) << std::endl;
    std::cout << "Done" << std::endl; 
    return 0;  
}