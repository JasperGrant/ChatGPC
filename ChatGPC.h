//Declaration of ChatGPC functions and macros
//Created by Jasper Grant
//2023-07-25

#ifndef CHATGPC_CHATGPC_H
#define CHATGPC_CHATGPC_H

#include "curl/curl.h"

//Required to set this for your api key
#define API_KEY "YOUR API KEY HERE"
//Config macros for conversation
#define MODEL "gpt-3.5-turbo"
#define TEMP "0.7"
#define OUTPUT_FILE "ChatGPC_output.txt"

void ask_GPT(char * prompt);

#endif //CHATGPC_CHATGPC_H
