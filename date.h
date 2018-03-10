#ifndef DATE_H
#define DATE_H

using namespace std;


class Date
{
	private:
		int year;
		int month;
		int day;
		int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	public:
		//constructor
		Date(int y, int m, int d) : year(y), month(m), day(d) {}

		//compare dates
		const bool operator< (Date b) const
		{
			int aDate = (this->getYear() * 10000)+(this->getMonth()*100)+(this->getDay());
			int bDate = (b.getYear() * 10000)+(b.getMonth()*100)+(b.getDay());
			return aDate < bDate;
		}

		const bool operator== (Date b) const
		{
			int aDate = (this->getYear() * 10000)+(this->getMonth()*100)+(this->getDay());
			int bDate = (b.getYear() * 10000)+(b.getMonth()*100)+(b.getDay());
			return aDate == bDate;
		}

		const bool operator> (Date b) const 
		{
			int aDate = (this->getYear() * 10000)+(this->getMonth()*100)+(this->getDay());
			int bDate = (b.getYear() * 10000)+(b.getMonth()*100)+(b.getDay());
			return aDate > bDate;
		}
		
		//convert to a number based on base year and current year
		const int dateToNum(int base_year) const
		{
			int num_years = this->getYear() - base_year;
			int num_days = 0;
			for(int i = 0; i < num_years; i++)
			{
				if ( (base_year+i%4) == 0 && ((base_year+i%100) != 0  || (base_year+i%400) == 0 ))
					num_days += 366;
				else
					num_days += 365;
			}
			
			for(int i = 0; i < this->getMonth()-1; i++)
			{
				num_days += days_in_month[i];
				if ( i == 1 && (this->getYear()%4) == 0 && ((this->getYear()%100) != 0  || (this->getYear()%400) == 0 ))
					num_days += 1;
			}
		
			num_days += this->getDay();
			
			return num_days;
		}
		
		//convert a number to a date
		void numToDate(int a, int base_year)
		{
			int i;
			int num_days = a;
			//remove the years from the num in order to find the number of years in it.
			for(i = 0; (num_days > 365) || (num_days > 366); i++)
			{
				cout << a << endl;
				if ( (base_year+i%4) == 0 && ((base_year+i%100) != 0  || (base_year+i%400) == 0 ))
					num_days -= 366;
				else
					num_days -= 365;
			}
			this->setYear(base_year+i);

			for(i = 0; (i == 1 && num_days > 28 ) || ((i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11) && num_days > 31) || ((i == 3 || i == 5 || i == 8 || i == 10) && num_days > 30); i++)
			{
				cout << num_days << endl;
				num_days -= days_in_month[i];
				if ( i == 1 && (this->getYear()%4) == 0 && ((this->getYear()%100) != 0  || (this->getYear()%400) == 0 ))
					num_days -= 1;
			}
			this->setMonth(i+1);
			this->setDay(num_days);
		}
		
		//setters and getters
		void setYear(int tts) {year = tts;}
		void setMonth(int tts) {month = tts;}
		void setDay(int tts) {day = tts;}
		
		int getYear() const {return year;}
		int getMonth() const {return month;}
		int getDay() const {return day;}
};


#endif