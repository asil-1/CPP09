get current year:

```cpp
#include <iostream>
#include <ctime>

int	main(void)
{
	std::time_t	current_time = std::time(NULL);
	std::tm*	calendar = std::localtime(&current_time);
	int			cyear = calendar->tm_year + 1900;

	std::cout << cyear << std::endl;
}
```
