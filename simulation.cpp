#include "simulation.h"

#include <cassert>
#include <stdexcept>

simulation::simulation(
    const double carrying_capacity,
    const double igr,
    const double ipd,
    const int n_generations
) : m_carrying_capacity{carrying_capacity},
    m_igr{igr},
    m_ipd{ipd},
    m_n_generations{n_generations}
{
  if (m_carrying_capacity < 0.0)
  {
    throw std::invalid_argument("carrying capacity must be zero or positive");
  }
  if (m_igr < 0.0)
  {
    throw std::invalid_argument("intrinsic growth rate must be zero or positive");
  }
  if (m_ipd < 0.0)
  {
    throw std::invalid_argument("carrying_capacity must be  zero or positive");
  }
  if (m_n_generations < 0)
  {
    throw std::invalid_argument("number of generations must be zero or positive");
  }
}

void simulation::run() noexcept
{
  double pd = m_ipd;
  for (int i=0; i!=m_n_generations; ++i)
  {
    m_pds.push_back(pd);
    pd += (pd * m_igr * (1.0 - (pd / m_carrying_capacity)));
  }
}

