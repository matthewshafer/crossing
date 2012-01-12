/**
 * @file
 * @brief Notification sender for boxcar.io
 * Allows one to send notifications to boxcar.io.  Requires the growl plugin to be enabled in boxcar
 * @author Matthew Shafer <matt@niftystopwatch.com>
*/

#include "crossing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

/**
 * @fn int crossing_send_notification
 * @param crossing_data Struct containing the information needed to send
 * @brief posts the notification to boxcar.io
*/
int crossing_send_notification(crossing_data *data)
{
	char *str;
	srand(time(NULL));
	int r = rand();
	CURL *handle = curl_easy_init();
	CURLcode res;
	const char *fsn = "notification[from_screen_name]=";
	const char *mess = "&notification[message]=";
	const char *sid = "&notification[from_remote_service_id]=";
	const char *from = curl_easy_escape(handle, data->from, strlen(data->from));
	const char *message = curl_easy_escape(handle, data->message, strlen(data->message));
	char randomnumberchar[10];
	int strlength = strlen(fsn) + strlen(mess) + strlen(from) + strlen(message) + strlen(sid) + strlen(randomnumberchar) + 1;
	
	snprintf(randomnumberchar, sizeof(randomnumberchar), "%d", r);
	printf("%s\n", data->username);
	printf("%s\n", data->password);
	printf("%s\n", data->from);
	printf("%s\n", data->message);
	printf("rand: %s\n", randomnumberchar);
	printf("rand len: %zi\n", strlen(randomnumberchar));
	printf("OG rand: %i\n", r);
	
	str = malloc(sizeof(char) * strlength);
	
	if(str == NULL)
	{
		// not allocated
		return 1;
	}
	
	// easier than having a bunch of strncat statements.
	snprintf(str, strlength, "%s%s%s%s%s%s", fsn, from, mess, message, sid, randomnumberchar);
	
	printf("%s\n", str);
	
	
	curl_easy_setopt(handle, CURLOPT_HTTPAUTH, (long)CURLAUTH_ANY);
	curl_easy_setopt(handle, CURLOPT_USERNAME, data->username);
	curl_easy_setopt(handle, CURLOPT_PASSWORD, data->password);
	curl_easy_setopt(handle ,CURLOPT_URL, "https://boxcar.io/notifications");
	curl_easy_setopt(handle, CURLOPT_POSTFIELDS, str);
	res = curl_easy_perform(handle);
	
	
	printf("%i\n", res);
	curl_easy_cleanup(handle);
	
	
	free(str);
	return 0;
}