package com.android.jerrystudy;

public class PlayerNative {
    /**
     * 这里加载有依赖关系
     */
    static {
        System.loadLibrary("avutil");
        System.loadLibrary("swresample");
        System.loadLibrary("avcodec");
        System.loadLibrary("avfilter");
        System.loadLibrary("swscale");
        System.loadLibrary("avformat");
        System.loadLibrary("native_ffmpeg");
    }


    /**
     * 音视频解码播放
     *
     * @param path
     * @param view
     */
    public native static void paly(String path, Object view);

    /**
     * 音视频解码停止
     *
     */
    public native static void stop();
}
