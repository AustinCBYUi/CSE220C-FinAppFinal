#ifndef FINACCOUNTS_HPP
#define FINACCOUNTS_HPP
#include <string>
#include <map>
#include <ostream>

class FinancialAccounts {
private:
	static std::map<int, FinancialAccounts> cc_accounts;
	static int next_id;
	int account_id;
	std::string institution_name;
	double principle_balance;
	double interest_rate;
public:
	std::map<int, FinancialAccounts>& get_ccaccounts_map();
	void get_accounts()const;
	void add_cc_account(const FinancialAccounts& cc_account);
	void find_account(int account_id) const;
	void input_cc_account();
	FinancialAccounts();
	void WriteToStream(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& out, const FinancialAccounts& account);
#endif // !FINACCOUNTS_HPP
