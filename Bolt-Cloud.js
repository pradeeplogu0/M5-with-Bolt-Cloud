setChartTitle('M5Stack Core2 with Bolt IoT')


var lineGraph1 = new boltGraph();
lineGraph1.setChartType("lineGraph");
lineGraph1.setAxisName('Time','Temp C');
lineGraph1.plotChart('time_stamp','temp');

var lineGraph2 = new boltGraph();
lineGraph2.setChartType("lineGraph");
lineGraph2.setAxisName('Time','Pressure Pa');
lineGraph2.plotChart('time_stamp','hum');
