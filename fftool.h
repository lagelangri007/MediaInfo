#ifndef __FFTOOL__
#define __FFTOOL__
#include <stdio.h>

extern "C"
{
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
}

namespace android{

#define DB(FMT,...)     printf("[%s][%d]"FMT"\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
class fftool
{
public:
    
    fftool();
    ~fftool();
    bool init(char* fileName);
    int64_t getDuration();
private:
    AVFormatContext *pFormatCtx;
};

};
#endif
