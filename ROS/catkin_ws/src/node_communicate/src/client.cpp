#include <ros/ros.h>
#include "node_communicate/info.h"

int main(int argc, char **argv)
{
    //初始化节点
    ros::init(argc, argv, "client");

    //创建句柄
    ros::NodeHandle node_h;

    //创建服务客户端
    ros::service::waitForService("/com_info");
    ros::ServiceClient Client = node_h.serviceClient<node_communicate::info>("/com_info");

    //定义数据
    node_communicate::info srv;
    srv.request.request = "Halo! Are you OK ?";


    Client.call(srv);

    //显示应答
    ROS_INFO("Response information : %s", srv.response.response.c_str());

    return 0;
}