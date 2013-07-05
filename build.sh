#!/bin/bash
#export SRVFRAME_ROOT=/usr/local/xunlei_community/comm/framework_1.5
export SERVER_ROOT=`pwd`
export CXX=gcc
time_day=`date  +'%Y%m%d'`
export SERVER_NAME=$1

if [ $# == 0 ];then
	echo quit make, try     ./build.sh gateway   for server selection     
	exit; 
fi
if [ $1 == 'init' ];then
rm -rf  obj/*  




fi


if [ $# == 0 ];then
	echo quit make, try     ./build.sh gateway   for server selection   
elif [ $# == 1 ];then
	cd src;
	if [ $1 == 'clean' ];then
		rm -f obj/*
		
		#make clean;
	elif [ $1 == 'gateway' ];then
	    #cd bin
	    #rm gateway_$time_day
	    #cd ..
	    cd src
		#export SERVER_NAME=$1_server
	    make -f makefile_gateway;
		make -f makefileobj
		#cd ..
		#cd bin
		#mv gateway gateway_$time_day
		#tar zcvf gateway_server.tar.gz  gateway_$time_day
		#cd ..
		#scp bin/gamebox_gate_$time_day hehengpan@essh.sandai.net:/tmp/hehengpan/doc2pdf_server_$time_day
		#scp bin/gamebox_gate_server.tar.gz  root2@10.10.10.199:/usr/local/netgame/gameboxgate/bin/gamebox_gate_server.tar.gz
		#scp bin/gamebox_gate_server.tar.gz  root2@10.10.1.58:/usr/local/netgame/gameboxgate/bin/gamebox_gate_server.tar.gz
		#scp bin/gamebox_gate_server_20121023  root2@10.10.10.199:/usr/local/netgame/gameboxgate/bin/gamebox_gate_server_20121023
	
#	elif [  $1 == 'disk_clean'  ];then
#		export SERVER_NAME=$1
	fi
fi
