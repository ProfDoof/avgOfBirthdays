
class Date
{
	private:
		int year;
		int month;
		int day;
		int[] days_in_month = {31,28}
	
	public:
		//constructor
		Date(int y, int m, int d) : year(y), month(m), day(d) {}

		//compare dates
		bool operator< (Date a, Date b)
		{
			int aDate = (a.getYear() * 10000)+(a.getMonth*100)+(a.getDay);
			int bDate = (b.getYear() * 10000)+(b.getMonth*100)+(b.getDay);
			return aDate < bDate;
		}
		
		//convert to a number based on base year and current year
		int dateToNum(Date a, int base_year)
		{
			num_years = a.getYear() - base_year;
			for(int i = 0; i < num_years; i++)
			{
				
			}
			
		}
		
		//convert a number to a date
		
		
		//setters and getters
		void setYear(int tts) {year = tts;}
		void setMonth(int tts) {month = tts;}
		void setDay(int tts) {day = tts;}
		
		int getYear() {return year;}
		int getMonth() {return month;}
		int getDay() {return day;}
}
