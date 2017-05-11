
#define __STDC_LIMIT_MACROS
extern "C"
{
#include <libavformat/avio.h>
#include <libavformat/url.h>
#include <libavutil/log.h>
}
#include <fftool.h>

#define DB(FMT,...)     printf("[%s][%d]"FMT"\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)


namespace android {

static void log_callback(void* ptr, int level, const char* fmt, va_list vl)
{
    char strout[256] = "[FFMpeg_Log]";
    vsnprintf(strout, sizeof(strout), fmt, vl);
    //printf("FF log %s \n", strout);
} 
fftool::fftool()
{
    pFormatCtx = NULL;
}
fftool::~fftool()
{
    if(pFormatCtx)
    {
        avformat_close_input(&pFormatCtx);
    }
}
bool fftool::init(char* fileName)
{
    av_log_set_callback(log_callback);
    av_register_all();

    pFormatCtx = avformat_alloc_context();
    if(avformat_open_input(&pFormatCtx,fileName,NULL,NULL)!=0){  
        printf("Couldn't open input stream.\n");  
        return false;  
    }  
    if(avformat_find_stream_info(pFormatCtx,NULL)<0){  
        printf("Couldn't find stream information.\n");  
        return false;  
    }  
    return true;
}

int64_t fftool::getDuration()
{
    if(pFormatCtx && pFormatCtx->duration != AV_NOPTS_VALUE)
    {
        printf("TEST----------->duration is  %lld \n",pFormatCtx->duration);
        return pFormatCtx->duration/1000/1000;
    }
    else
    {
        printf("TEST----------->duration is AV_NOPTS_VALUE \n");
        return 0;
    }
}

};
