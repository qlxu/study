#include <jni.h>
#include <string>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <unistd.h>
#include <android/log.h>

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,"TAG",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"TAG",FORMAT,##__VA_ARGS__);

extern "C" {
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavfilter/avfilter.h"
#include "libavutil/imgutils.h"
#include "libavutil/avutil.h"
#include "libavfilter/buffersink.h"
#include "libavfilter/buffersrc.h"
#include "libavcodec/avcodec.h"
}

extern "C"
/**
 * 播放
 */
JNIEXPORT void JNICALL Java_com_android_jerrystudy_PlayerNative_paly
        (JNIEnv *env, jclass cls, jstring path_, jobject view) {
    const char *path = env->GetStringUTFChars(path_, 0);
//    LOGE("%s", "play()"+*path);
//    //注册所有的编解码器
//    av_register_all();
//    int ret;
//    //封装格式上线文
//    AVFormatContext *fmt_ctx = avformat_alloc_context();
//    //打开输入流并读取头文件。此时编解码器还没有打开
//    if (avformat_open_input(&fmt_ctx, path, NULL, NULL) < 0) {
//        return;
//    }
//    //获取信息
//    if (avformat_find_stream_info(fmt_ctx, NULL) < 0) {
//        return;
//    }
//    //获取视频流的索引位置
//    int video_stream_index = -1;
//    for (int i = 0; i < fmt_ctx->nb_streams; i++) {
//        if (fmt_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
//            video_stream_index = i;
//            LOGE("找到视频流索引位置video_stream_index=%d", video_stream_index);
//            break;
//        }
//    }
//    if (video_stream_index == -1) {
//        LOGE("未找到视频流索引");
//    }
//    ANativeWindow *nativeWindow = ANativeWindow_fromSurface(env, view);
//    if (nativeWindow == NULL) {
//        LOGE("ANativeWindow_fromSurface error");
//        return;
//    }
//    //绘制时候的缓冲区
//    ANativeWindow_Buffer outBuffer;
//    //获取视频流解码器
//
//    AVCodecContext *codec_ctx = avcodec_alloc_context3(NULL);
//    avcodec_parameters_to_context(codec_ctx, fmt_ctx->streams[video_stream_index]->codecpar);
//    AVCodec *avCodec = avcodec_find_decoder(codec_ctx->codec_id);
//    //打开解码器
//    if ((ret = avcodec_open2(codec_ctx, avCodec, NULL)) < 0) {
//        ret = -3;
//        return;
//    }
//    //循环从文件读取一帧压缩数据
//    //开始读取视频
//    int y_size = codec_ctx->width * codec_ctx->height;
//    AVPacket *pkt = (AVPacket *) malloc(sizeof(AVPacket));//分配一个packet
//    av_new_packet(pkt, y_size);//分配packet的数据
//    AVFrame *yuvFrame = av_frame_alloc();
//    AVFrame *rgbFrame = av_frame_alloc();
//    // 颜色转换器
//    SwsContext *m_swsCtx = sws_getContext(codec_ctx->width, codec_ctx->height, codec_ctx->pix_fmt,
//                                          codec_ctx->width,
//                                          codec_ctx->height, AV_PIX_FMT_RGBA, SWS_BICUBIC, NULL,
//                                          NULL, NULL);
//
//
//    LOGE("开始解码");
//    int index = 0;
//    while (1) {
//        if (av_read_frame(fmt_ctx, pkt) < 0) {
//            //这里就认为视频读完了
//            break;
//        }
//        if (pkt->stream_index == video_stream_index) {
//            //视频解码
//            ret = avcodec_send_packet(codec_ctx, pkt);
//            if (ret < 0 && ret != AVERROR(EAGAIN) && ret != AVERROR_EOF) {
//                LOGE("avcodec_send_packet ret=%d", ret);
//                av_packet_unref(pkt);
//                continue;
//            }
//            //从解码器返回解码输出数据
//            ret = avcodec_receive_frame(codec_ctx, yuvFrame);
//            if (ret < 0 && ret != AVERROR_EOF) {
//                LOGE("avcodec_receive_frame ret=%d", ret);
//                av_packet_unref(pkt);
//                continue;
//            }
//            //avcodec_decode_video2(codec_ctx,yuvFrame,&got_pictue,&pkt);
//            sws_scale(m_swsCtx, (const uint8_t *const *) yuvFrame->data, yuvFrame->linesize, 0,
//                      codec_ctx->height, rgbFrame->data, rgbFrame->linesize);
//            //设置缓冲区的属性
//            ANativeWindow_setBuffersGeometry(nativeWindow, codec_ctx->width, codec_ctx->height,
//                                             WINDOW_FORMAT_RGBA_8888);
//            ret = ANativeWindow_lock(nativeWindow, &outBuffer, NULL);
//            if (ret != 0) {
//                LOGE("ANativeWindow_lock error");
//                return;
//            }
//            av_image_fill_arrays(rgbFrame->data, rgbFrame->linesize,
//                                 (const uint8_t *) outBuffer.bits, AV_PIX_FMT_RGBA,
//                                 codec_ctx->width, codec_ctx->height, 1);
//            //fill_ANativeWindow(&outBuffer,outBuffer.bits,rgbFrame);
//            //将缓冲区数据显示到surfaceView
//            ret = ANativeWindow_unlockAndPost(nativeWindow);
//            if (ret != 0) {
//                LOGE("ANativeWindow_unlockAndPost error");
//                return;
//            }
//            LOGE("成功显示到缓冲区%d次", ++index);
//        }
//        av_packet_unref(pkt);
//        usleep(1000 * 8);
//
//    }
//
//    av_frame_free(&rgbFrame);
//    avcodec_close(codec_ctx);
//    sws_freeContext(m_swsCtx);
//    avformat_close_input(&fmt_ctx);
//    ANativeWindow_release(nativeWindow);
//    env->ReleaseStringUTFChars(path_, path);
//    LOGI("解析完成");


    av_register_all();
    AVCodec *c_temp = av_codec_next(NULL);
    while (c_temp != NULL)
    {
        switch (c_temp->type)
        {
            case AVMEDIA_TYPE_VIDEO:
                LOGI("[Video]:%s", c_temp->name);
                break;
            case AVMEDIA_TYPE_AUDIO:
                LOGI("[Audio]:%s", c_temp->name);
                break;
            default:
                LOGI("[Other]:%s", c_temp->name);
                break;
        }
        c_temp = c_temp->next;
    }
    // TODO

    env->ReleaseStringUTFChars(path_, path);
}

/**
 * 暂停
 */
JNIEXPORT void JNICALL Java_com_android_jerrystudy_PlayerNative_stop
        (JNIEnv *env, jclass cls) {
    LOGE("%s", "stop()");
}