#define TMP36_INPUT 0
#define CDS_INPUT 1

void setup() {
  Serial.begin(9600);
}
void loop() {
  // Temperature from TMP36
  int temp_value = analogRead(TMP36_INPUT);
  // converting that reading to voltage
  float voltage = temp_value * 5.0 * 1000;  // in mV
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10 ;

  // Lux from CdS (LDR)
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));
//  Serial.print("AA07,");
  Serial.print(tempC);
  Serial.print(",");
  Serial.println(lux);
  
  delay(1000);
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10.0;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
var readData="";
var temp = "";
var lux = "";
var mdata = [];
 firstcommaidx = 0;

parser.on("data", (data) => {
  readData = data.toString();
  firstcommaidx = readData.indexOf(",");
  if(firstcommadix > 0) {
    temp = readData.substring(0, firstcommaidx);
    lux = readData.substring(firstcommadix +1);
    readdata = "";

    dStr = getDateString();
    mdata[0] = dStr;
    mdata[1] = temp;
    mdata[2] = lux;
    console.log("AA07," + mdata);
    io.sockets.emit("message", mdata);
  } else{
    console.log(readData);
  }
});
