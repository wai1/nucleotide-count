#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {
	
	counter::counter(const std::string& dnaString)
		:nucleotide_totals { {'A', 0}, { 'T', 0 }, { 'C', 0 }, { 'G', 0 }}
	{
		for (char element : dnaString)
		{
			nucleotide_validity(element);
			++nucleotide_totals[element];
		}
	}

	void counter::nucleotide_validity(char nucleotide) const
	{
		if (nucleotide_totals.find(nucleotide) == nucleotide_totals.end())
			throw std::invalid_argument("Incorrect nucleotide.");
	}

	const std::map<char, int>& counter::nucleotide_counts() const
	{
		return nucleotide_totals;
	}

	int counter::count(char nucleotide) const
	{
		nucleotide_validity(nucleotide);
			
		return nucleotide_totals.at(nucleotide);
	}

}  // namespace nucleotide_count

