/**
 * @file
 * @brief Notification sender for boxcar.io
 * Allows one to send notifications to boxcar.io.  Requires the growl plugin to be enabled in boxcar
 * @author Matthew Shafer <matt@niftystopwatch.com>
*/

/**
 * @struct crossing_data
 * @brief Holds the data needed to send the notification
 * Holds the data needed to send the notification, username/password/from(where the notification is from)/message
*/

/**
 * @fn int crossing_send_notification
 * @param crossing_data Struct containing the information needed to send
 * @brief posts the notification to boxcar.io
*/

#ifndef H_CROSSING
#define H_CROSSING

typedef struct {
 char *username;
 char *password;
 char *from;
 char *message;

} crossing_data;


int crossing_send_notification(crossing_data *data);

#endif