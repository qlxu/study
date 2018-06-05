package com.android.jerrystudy;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

import java.io.File;

public class MainActivity extends AppCompatActivity {


    private com.android.jerrystudy.VideoView mVideo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mVideo = findViewById(R.id.video);

        
    }


    public void paly(View view) {
        final String dir = Environment.getExternalStorageDirectory() + File.separator + "Download";
        final String path = dir + File.separator + "1.mp4";
        if (new File(path).exists()) {
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    PlayerNative.paly(path, mVideo.getHolder().getSurface());
                }
            });
        } else {
            System.out.println("文件不存在");
        }
    }

    public void stop(View view) {
        PlayerNative.stop();
    }
}