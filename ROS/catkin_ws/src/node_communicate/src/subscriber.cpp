#include <ros/ros.h>
#include "node_communicate/message.h"

//接受订阅消息
void Info_Callback(const node_communicate::message::ConstPtr& msg)
{
    //打印接收消息
    ROS_INFO("Subscribe information: %s", msg->info.c_str());
}

int main(int argc, char **argv)
{
    //ROS节点初始化
    ros::init(argc, argv, "subscriber");

    //创建节点句柄
    ros::NodeHandle node_h;

    //创建subscriber,topic， 注册回调函数
    ros::Subscriber sub_info = node_h.subscribe("/com_msgs", 10, Info_Callback);

    //等待回调函数
    ros::spin();

    return 0;
}

