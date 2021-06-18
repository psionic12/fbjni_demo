package com.example.fbjni_demo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);

        DemoClassJavaSide demo = new DemoClassJavaSide();
        tv.setText(demo.getString() + "\n"
                + demo.getAndSetInt(1) + "\n"
                + demo.getObjectFromCpp().getI() + "\n"
                +demo.sendObjectToCpp(new NormalJavaClass(4)));
        demo = null;
        System.gc();
    }
}