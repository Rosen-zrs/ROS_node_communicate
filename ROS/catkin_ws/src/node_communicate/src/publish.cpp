#include <ros/ros.h>
#include "node_communicate/message.h"

int main(int argc, char **argv)
{
    //ROS节点初始化
    ros::init(argc, argv, "publish");

    //创建节点句柄
    ros::NodeHandle node_h;

    //创建一个Pulisher， 发布topic
    ros::Publisher pub_info = node_h.advertise<node_communicate::message>("/com_msgs", 10);

    //设置循环的频率
    ros::Rate loop_rate(1);

    while(ros::ok())
    {
        //初始化消息
        node_communicate::message msg;
        msg.info = "Hey! You are successful!";

        //发布消息
        pub_info.publish(msg);

        ROS_INFO("Publish information : %s", msg.info.c_str());

        //按照循环频率延时
        loop_rate.sleep();
    }

    return 0;
}
