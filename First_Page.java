package com.pranomvignesh.clockscalendars;

import android.content.Intent;
import android.icu.util.*;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import java.util.*;

public class First_Page extends AppCompatActivity {
    Button Clocks;
    Button Calendars;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_first__page);
        Button Clocks=(Button)findViewById(R.id.Clocks_Button);
        final Button Calendars=(Button)findViewById(R.id.Calendar_Button);

        Clocks.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent=new Intent(getApplicationContext(),ClockActivity.class);
                startActivity(intent);

            }
        });

        Calendars.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent=new Intent(getApplicationContext(),Calendar.class);
                startActivity(intent);
            }
        });



    }
}
