#include <fftool.h>

using namespace android;

int main(int argc, char ** argv)
{
    char* filename = argv[1];
    DB("TEST-----------> %s \n",filename);
    fftool tool;
    if(tool.init(filename))
    {
        DB("TEST----------->duration is  %lld \n",tool.getDuration());
    }
    else
    {
        DB("TEST----------->init is  failed!!! \n");
    }
    //while(1)
    {
        //usleep(1000000);
    }
    return 0;
}
