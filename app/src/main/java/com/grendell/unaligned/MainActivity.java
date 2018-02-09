package com.grendell.unaligned;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("unaligned-test");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView arch = findViewById(R.id.arch);
        arch.setText(getArch());

        TextView pointer = findViewById(R.id.pointer);
        String address = String.format("%#018x", unalignedTest());
        pointer.setText(address);
    }

    public static native String getArch();

    public static native long unalignedTest();
}