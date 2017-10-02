package com.pranomvignesh.clockscalendars;

import android.content.Context;
import android.renderscript.ScriptGroup;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import static android.R.attr.duration;
import static android.widget.Toast.makeText;

public class Calendar extends AppCompatActivity {
    TextView Output;
    Button Find;
    EditText Input_date;
    EditText Input_month;
    EditText Input_year;
    int OddDays;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calendar);
        Output=(TextView)findViewById(R.id.Output_Day);
        Input_date=(EditText)findViewById(R.id.Date_input);
        Input_month=(EditText)findViewById(R.id.Month_input);
        Input_year=(EditText)findViewById(R.id.Year_input);
        Find=(Button)findViewById(R.id.Find_button);
        Find.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                OddDays=0;
                Toast Null=Toast.makeText(getApplicationContext(),"Enter Date and Try",Toast.LENGTH_SHORT);
                Toast Incorrect=Toast.makeText(getApplicationContext(),"Incorrect Date",Toast.LENGTH_SHORT);

                String datestr=Input_date.getText().toString();
                String monthstr=Input_month.getText().toString();
                String yearstr=Input_year.getText().toString();

               if(datestr.isEmpty()||monthstr.isEmpty()||yearstr.isEmpty()){Null.show();Output.setText(" ");return;}

                int date=Integer.parseInt(datestr);
                int month=Integer.parseInt(monthstr);
                int year=Integer.parseInt(yearstr);

                if(date==0||date>31||month==0||month>12||year==0){Incorrect.show();Output.setText(" ");return;}

                switch (month)
                {
                    case 2:
                        if(date>29){Incorrect.show();Output.setText(" ");return;}
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if(date>=31){Incorrect.show();Output.setText(" ");return;}
                }

                if(year%100==0)
                {
                    if(year%400!=0&&month==2&&date>28){Incorrect.show();Output.setText(" ");return;}
                }
                else if(year%4!=0&&month==2&&date>28){Incorrect.show();Output.setText(" ");return;}

                int staticyear = year;
                year--;
                year%=400;
                if (year > 300) {
                    OddDays+=1;
                    year -= 300;
                } else if (year > 200 && year < 300) {
                    OddDays += 3;
                    year -= 200;
                } else if (year > 100 && year < 200) {
                    OddDays += 5;
                    year -= 100;
                }
                int leapyears;
                leapyears = year / 4;
                year = year - leapyears;
                OddDays+=((leapyears * 2) + (year));
                switch (month)//Adding Month Odd Days
                {
                    case 1:
                        OddDays += 0;
                        break;
                    case 2:
                        OddDays += 3;
                        break;
                    case 3:
                        OddDays += 3;
                        break;
                    case 4:
                        OddDays += 6;
                        break;
                    case 5:
                        OddDays += 8;
                        break;
                    case 6:
                        OddDays += 11;
                        break;
                    case 7:
                        OddDays += 13;
                        break;
                    case 8:
                        OddDays += 16;
                        break;
                    case 9:
                        OddDays += 19;
                        break;
                    case 10:
                        OddDays += 21;
                        break;
                    case 11:
                        OddDays += 26;
                        break;
                    case 12:
                        OddDays += 26;
                        break;


                }
                OddDays += date;//Adding Date
                if(staticyear%100==0)
                {
                    if(staticyear%400==0)OddDays+=1;
                }
                else if (staticyear % 4 == 0 && month > 2) OddDays += 1;//Leap year Coding
                OddDays %= 7;
                switch (OddDays)//Finding day
                {
                    case 0:
                        Output.setText("Sunday");
                        break;
                    case 1:
                        Output.setText("Monday");
                        break;
                    case 2:
                        Output.setText("Tuesday");
                        break;
                    case 3:
                        Output.setText("Wednesday");
                        break;
                    case 4:
                        Output.setText("Thursday");
                        break;
                    case 5:
                        Output.setText("Friday");
                        break;
                    case 6:
                        Output.setText("Saturday");
                        break;


                }

            }
        });
    }
}
