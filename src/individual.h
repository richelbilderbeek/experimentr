#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>

///Actually, a genome for now
class individual
{
public:
  individual(const std::string& genome);
  const std::string& get_genotype() const noexcept { return m_genome; }

private:
  std::string m_genome;
};

#endif // INDIVIDUAL_H
