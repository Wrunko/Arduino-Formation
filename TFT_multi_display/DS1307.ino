
void readAndShowDatetime() {
  tmElements_t tm;

  if (RTC.read(tm)) {
    //writeDateTime(tm);
  }
}