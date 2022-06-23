#include <stdio.h>
#include "mosquitto.h"

void my_log_callback(struct mosquitto *mosq, void * obj, int level, const char * msg) {
	//Ignore level, just print it
	fprintf(stderr, "level: %d, msg: %s \n", level, msg);
}

void my_connect_callback(struct mosquitto *mosq, void * obj, int rc) {
	if(rc !=0) {
		fprintf(stderr, "Connection failed, return code = %d \n", rc);
	}

	fprintf(stderr, "Connection success! Subscribe to test/topic\n");
	mosquitto_subscribe(mosq, NULL, "test/topic", 0);
}

void my_message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg) {
       	fprintf(stderr, "New message with topic %s: %s\n", msg->topic, (char *) msg->payload);
}

void my_publish_callback (struct mosquitto * mosq, void * obj, int mid) {
	fprintf(stderr, "message id %d\n", mid);
}



int main(int argc, char *argv[])
{
	int i;
	char host[64];
	int port = 1883;
	int keepalive = 60;
	bool clean_session = true;
	struct mosquitto *mosq = NULL;
	char mqMsg[64] = {0,};

	sprintf(host, "broker.hivemq.com");

	mosquitto_lib_init();
	mosq = mosquitto_new(NULL, clean_session, NULL);

	if(!mosq){
		fprintf(stderr, "Error: Out of memory.\n");
		return 1;
	}

	mosquitto_log_callback_set(mosq, my_log_callback);
	mosquitto_connect_callback_set(mosq, my_connect_callback);
	mosquitto_message_callback_set(mosq, my_message_callback);
	mosquitto_publish_callback_set(mosq, my_publish_callback);

	if(mosquitto_connect(mosq, host, port, keepalive)){
		fprintf(stderr, "Unable to connect.\n");
		return 1;
	}


        mosquitto_loop_forever(mosq, -1, 1);

	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
	return 0;
}
