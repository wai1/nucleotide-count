#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace nucleotide_count {

	class counter {
	private:
		std::map<char, int> nucleotide_totals;
		void nucleotide_validity(char nucleotide) const;

	public:
		explicit counter(const std::string& nucleotide);
		const std::map<char, int>& nucleotide_counts() const;  
		int count(char nucleotide) const;  
	};

}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H