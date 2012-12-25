/*
Time:2012Äê12ÔÂ25ÈÕ13:21:04
Author: uestczhangchao@gmail.com
Desc: this file is uesed to learn the basic concept of hadoop bistream.
*/

#include "hadoop_mapred.h"
#include <iostream>
#include <map>
#include <iterator>
#include <string.h>
#include <sstream>
using namespace std;

class bicat_map_t : public hadoop_mapper_t {
public :
    virtual int on_task_begin()
    {
    	return 0;
    }

	/*map function, it will split each input line into words, and emit the result to reducer*/
    virtual int map(const hadoop_map_input_t& input)
    {
    	int32_t key_len;
    	char *key = (char *)input.key(key_len);

    	int32_t val_len;
    	char *val = (char *)input.value(val_len);
        val[val_len] = '\0';

        char *word = strtok(val," ,\t");
        int32_t word_len = 0;
        while(word != NULL)
        {
            word_len = strlen(word);
            emit(word,word_len,"1",1);
            word = strtok(NULL," ,\t");
        }

    	return 0;
    }

    virtual int on_task_end()
    {
    	return 0;
    }
};

class bicat_reduce_t : public hadoop_reducer_t {
public :
    virtual int on_task_begin()
    {
    	return 0;
    }

    virtual int reduce(hadoop_reduce_input_t *input)
    {
        int32_t  key_len;

        char *key = (char*)input->key(key_len);
        map<string,int32_t> word2count;
        map<string,int32_t>::iterator it;
        
        while (input->next_value()) {
            key = (char*)input->key(key_len);
            
            int32_t  val_len;
            char *val = (char*)input->value(val_len);
            it = word2count.find(key);
            if(it != word2count.end())
            {
                (it->second)++;
            }
            else
            {
                word2count.insert(make_pair(key,1));
            }
        }

        for(it = word2count.begin(); it!=word2count.end(); ++it)
        {
            const char *word = (it->first).c_str();
            int32_t wordnum = it->second;
            stringstream wordcount;
            wordcount << wordnum;
            const char *wc = wordcount.str().c_str();
            emit(word, strlen(word), wc, strlen(wc));
        }
        return 0;

        /* int32_t  key_len;
         char *key = (char*)input->key(key_len);
                     
         while (input->next_value()) {
                key = (char*)input->key(key_len);
                                   
                int32_t  val_len;
                char *val = (char*)input->value(val_len);
                                                      
                emit(key, key_len, val, val_len);
         
         }   
  
         return 0;*/


    }


    virtual int on_task_end()
    {
    	return 0;
    }
};

USING_MAPPER(bicat_map_t);
USING_REDUCER(bicat_reduce_t);

int main(int argc, char *argv[])
{
    hadoop_framework_t  framework;    
    framework.init(argc, argv);
    return framework.run();
}

