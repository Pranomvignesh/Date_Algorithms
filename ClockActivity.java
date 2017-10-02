package com.pranomvignesh.clockscalendars;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import static com.pranomvignesh.clockscalendars.R.string.angle;
import static java.lang.Math.abs;

public class ClockActivity extends AppCompatActivity {
    Button Angle;
    TextView Result_Angle;
    EditText Hour;
    EditText Min;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_clock);
        Angle=(Button)findViewById(R.id.Find_angle);
        Result_Angle=(TextView)findViewById(R.id.Angle_output);
        Hour=(EditText)findViewById(R.id.HourInput);
        Min=(EditText)findViewById(R.id.MinuteInput);

        Angle.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String hh=Hour.getText().toString();
                String mm=Min.getText().toString();
                if(!hh.isEmpty()&&!mm.isEmpty()) {
                    int hour = Integer.parseInt(hh);
                    int min = Integer.parseInt(mm);

                    Toast Incorrect = Toast.makeText(getApplicationContext(), "Enter Correct Time", Toast.LENGTH_SHORT);

                    if (hour <= 0 || hour > 12 || min <= 0 || min > 60) {
                        Incorrect.show();
                        Result_Angle.setText(" ");
                        return;
                    }
                    {
                        float angle = abs((float) (30 * hour - (5.5 * min)));
                        Result_Angle.setText(Float.toString(angle) + " Degrees");
                    }
                }
                else {
                    Toast Null = Toast.makeText(getApplicationContext(), "Enter Time and try again", Toast.LENGTH_SHORT);
                    Null.show();
                    Result_Angle.setText(" ");
                    return;
                }
            }
        });
    }

}
