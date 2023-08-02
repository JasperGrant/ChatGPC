//Tests for ChatGPC Library
//Created by Jasper Grant
//2023-07-25

//TODO: Much more robust tests

#include "ChatGPC.h"
#include "assert.h"

int main(void){

    //Tests to see if output file has been written to after asking ChatGPT
    ask_GPT("Tell me something cool");
    assert(fopen(OUTPUT_FILE, "r"));
    //After printing to file more advanced response parsing can be done here


}