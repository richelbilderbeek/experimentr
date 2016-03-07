#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#pragma GCC diagnostic ignored "-Wextra"
#include <Rcpp.h>
#pragma GCC diagnostic pop

#include "individual.h"


char toggle_case(const char c)
{
  if (std::isupper(c)) { return std::tolower(c); }
  assert(std::islower(c));
  return std::toupper(c);
}

double get_genotype_frequency(const std::string& genotype, const std::vector<individual>& population)
{
  const int n{
    static_cast<int>(
      std::count_if(std::begin(population),std::end(population),
        [genotype](const individual& i) { return i.get_genotype() == genotype; }
      )
    )
  };
  const int sz{static_cast<int>(population.size())};
  const double f{static_cast<double>(n)/static_cast<double>(sz)};
  assert(f >= 0.0);
  assert(f <= 1.0);
  return f;

}

individual create_offspring(const individual& father, const individual& mother, const double mutation_rate, std::mt19937 rng_engine)
{
  const auto genotype_father = father.get_genotype();
  const auto genotype_mother = mother.get_genotype();
  assert(genotype_mother.size() == genotype_father.size());
  assert(genotype_mother.size() == 2);
  std::string genotype_kid;
  std::uniform_int_distribution<int> event(0,3);
  switch(event(rng_engine))
  {
    case 0: genotype_kid = genotype_father; break;
    case 1: genotype_kid = genotype_mother; break;
    case 2: genotype_kid += genotype_father[0]; genotype_kid += genotype_mother[1]; break;
    case 3: genotype_kid += genotype_mother[0]; genotype_kid += genotype_father[1]; break;
    default: assert(!"Should not get here");
  }
  assert(genotype_kid.size() == 2);
  std::uniform_real_distribution<double> mutation(0.0,1.0);
  if (mutation(rng_engine) < mutation_rate) { genotype_kid[0] = toggle_case(genotype_kid[0]); }
  if (mutation(rng_engine) < mutation_rate) { genotype_kid[1] = toggle_case(genotype_kid[1]); }
so
  return individual(genotype_kid);
}


// [[Rcpp::export]]
void do_simulation(const std::string csv_filename)
{
  std::ofstream file(csv_filename);
  file << "t" << ",f_ab,f_aB,f_Ab,f_AB\n";

  const int seed{42};
  std::mt19937 rng_engine{seed};
  double mutation_rate{0.001};

  //Initialize population with 'ab'
  const int population_size{1000};
  const int n_generations{100};
  std::vector<individual> population(population_size,individual("aB"));
  std::uniform_int_distribution<int> indices(0,population_size - 1);


  for (int i=0; i!=n_generations; ++i)
  {
    //Save genotype frequencies
    file
      << i
      << get_genotype_frequency("ab",population) << ", "
      << get_genotype_frequency("aB",population) << ", "
      << get_genotype_frequency("Ab",population) << ", "
      << get_genotype_frequency("AB",population) << '\n';
    //Make individuals mate and reproduce with mutation
    std::vector<individual> next_population;
    next_population.reserve(population_size);
    for (int i=0; i!=population_size; ++i)
    {
      const int father_index{indices(rng_engine)};
      assert(father_index >= 0);
      assert(father_index < static_cast<int>(population.size()));
      const int mother_index{indices(rng_engine)};
      assert(mother_index >= 0);
      assert(mother_index < static_cast<int>(population.size()));
      individual kid{create_offspring(population[father_index], population[mother_index], mutation_rate, rng_engine) };
      if (kid.get_genotype() == "AB") { --i; continue; }
      next_population.push_back(kid);
    }
    assert(population.size() == next_population.size());
    population = next_population;
  }
}
