#!/bin/sh
exe="cam_lidar" #需发布的程序名称
des="/home/d_542/Desktop/host_player/" #步骤一中新建目录的完整路径
deplist=$(ldd $exe|awk '{if (match($3,"/")){printf("%s "),$3}}')
cp $deplist $des
