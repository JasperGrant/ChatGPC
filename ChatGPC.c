//Definition of ChatGPC functions
//Created by Jasper Grant
//2023-07-25

#include "ChatGPC.h"

//These macros do not need to be changed, just to make weird string sizes more readable
#define FORMAT_STR_LEN 117
#define API_KEY_STR_LEN 75

//TODO:Handle other outputs other then just writing to output file
//Function to write individual bytes to output file
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

//Enter a prompt and ChatGPT will write a response to an output file of your choosing
void ask_GPT(char * input){
    //TODO: Sanitize input

    //Initialize curl
    CURL * curl = curl_easy_init();

    //Initialize output file
    FILE *fp = fopen(OUTPUT_FILE, "wb");

    //If initialization succeeded
    if(curl){
        //Set URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/chat/completions");

        //Setup prompt
        char prompt[strlen(input) + FORMAT_STR_LEN];
        //FORMAT_STR_LEN is based on length of this generic prompt
        sprintf(prompt, "{\n"
                        "     \"model\": \"%s\",\n"
                        "     \"messages\": [{\"role\": \"user\", \"content\": \"%s\"}],\n"
                        "     \"temperature\": %s\n"
                        "   }", MODEL, input, TEMP);
        //Set request type to post and content to prompt
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, prompt);

        //Add content type header
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        //Add API key header
        char api_key_str[API_KEY_STR_LEN];
        //API_KEY_LEN is based on the length of this header
        sprintf(api_key_str, "Authorization: Bearer %s", API_KEY);
        headers = curl_slist_append(headers, api_key_str);

        //Set callback function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        //Send result
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        //Capture result
        CURLcode res = curl_easy_perform(curl);

        //TODO: Change function return type and make useful return codes
    }
    //Cleanup curl
    curl_easy_cleanup(curl);

    fclose(fp);
}


