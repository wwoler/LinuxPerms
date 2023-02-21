#include "Database.h"


struct test
{
	void operator()(void)
	{
		DataBase* db;

		try
		{
			db = new DataBase();
		}
		catch (std::exception const& ex)
		{
			std::cerr << ex.what() << '\n';
			return;
		}

		auto kekw = db->read_users();

		std::cout << "Old data\n";

		if (kekw.empty())
			std::cout << "No data\n\n";

		for (auto const& v : kekw)
		{
			std::cout << v;
		}


		std::cout << "Override data\n";

		User user2("3", "3", "3");
		db->write_user(user2);
		


		auto kek1w = db->read_users();


		for (auto const& v : kek1w)
		{
			std::cout << v;
		}

		delete db;
	}
};


int main()
{
	test()();
	std::cout << "Press enter to continue ...";
    std::cin.get(); 
	return 0;
}