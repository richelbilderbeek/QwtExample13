#ifndef SIMULATION_H
#define SIMULATION_H

#include <iosfwd>
#include <vector>

struct simulation
{
  /// @param carrying_capacity the carrying capacity, in individual density
  /// @param igr Intrinsic Growth Rate, in population density per generation
  /// @param ipd Initial Population Density
  /// @param n_generation the number of generations
  simulation(
    const double carrying_capacity,
    const double igr,
    const double ipd,
    const int n_generations
  );

  const auto& get_population_densities() const noexcept { return m_pds; }
  void run() noexcept;

  private:
  const double m_carrying_capacity;
  const double m_igr;
  const double m_ipd;
  const int m_n_generations;

  ///Population Densities
  std::vector<double> m_pds;
};

std::ostream& operator<<(std::ostream& os, const simulation& s) noexcept;

#endif // SIMULATION_H
