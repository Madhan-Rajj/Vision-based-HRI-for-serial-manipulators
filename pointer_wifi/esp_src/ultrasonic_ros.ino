#include <ros.h>
#include <std_msgs/Int16.h>

const int trig = 2;
const int echo = 4;

#define speed_of_sound 0.034
long duration;
float distance_cm;

ros::NodeHandle  nh;

std_msgs::Int16 ultrasonic_msg
ros::Publisher ultrasonic_node("ultrasonic_values ", &ultrasonic_msg );
void setup(){
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    nh.initNode();
    nh.advertise(ultrasonic_node);
}

void loop(){

    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

      duration = pulseIn(echo, HIGH);
      distance_cm = ((duration*speed_of_sound)/2);
      ultrasonic_node.publish(&ultrasonic_msg)
      nh.spinOnce();
      delay(1);

}
