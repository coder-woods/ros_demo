#include "ros/ros.h"
#include "std_msgs/String.h"

//接受到订阅的消息后，会进入消息回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    //将接收到的消息打印出来
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char** argv) 
{
    //初始化ROS节点
    ros::init(argc, argv, "sub_demo");

    //创建节点句柄
    ros::NodeHandle n;

    ros::Subscriber sub =n.subscribe("chatter", 1000, chatterCallback);

    ros::spin();

    return 0;
}