#include <ros/ros.h>
#include "node_communicate/info.h"


bool Info_Callback(node_communicate::info::Request &req, node_communicate::info::Response &res)
{
    //现实请求信息
    ROS_INFO("Request information: %s", req.request.c_str());

    //设置应答数据
    res.response = "I am OK";

    return true;
}


int main(int argc, char **argv)
{
    //初始化节点
    ros::init(argc, argv, "server");

    //创建节点句柄
    ros::NodeHandle node_h;
    
    //创建server,设置回调函数
    ros::ServiceServer service = node_h.advertiseService("/com_info", Info_Callback);

    //等待回调函数
    ros::spin();

    return 0;
}