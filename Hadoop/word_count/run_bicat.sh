#!/bin/sh

# run bicat
$HADOOP_HOME/bin/hadoop bistreaming \
	-jobconf mapred.job.name="test bicat" \
	-jobconf mapred.map.tasks=2 \
	-jobconf mapred.reduce.tasks=2 \
	-inputformat org.apache.hadoop.mapred.SequenceFileAsBinaryInputFormat \
	-outputformat org.apache.hadoop.mapred.TextOutputFormat \
	-mapper "bicat" \
	-file ./bicat \
	-reducer "bicat" \
	-input /user/test/libmapred/input \
	-output /user/test/libmapred/output 

