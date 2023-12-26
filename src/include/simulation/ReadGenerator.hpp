/**
 ** DRAGEN Open Source Software
 ** Copyright (c) 2019-2020 Illumina, Inc.
 ** All rights reserved.
 **
 ** This software is provided under the terms and conditions of the
 ** GNU GENERAL PUBLIC LICENSE Version 3
 **
 ** You should have received a copy of the GNU GENERAL PUBLIC LICENSE Version 3
 ** along with this program. If not, see
 ** <https://github.com/illumina/licenses/>.
 **
 **/
#pragma once
#include "reference/ReferenceDir.hpp"
#include "simulation/Variant.hpp"
#include "simulation/SamPrinter.hpp"

namespace dragenos{
namespace simulation{

class ReadGenerator{
public:
  SamPrinter& output_;
  ReadGenerator(SamPrinter& output):output_(output)
  {
  }
  void generateReads(const reference::HashtableConfig::Sequence& s, const reference::ReferenceDir7& referenceDir
      , const Variants& vars,const std::string& seqName);
private:
  std::string extractRef(
      const reference::ReferenceDir7 &referenceDir,
      const reference::HashtableConfig::Sequence &s, std::uint64_t refPos,
      std::uint32_t matchLen);
  std::string generateSeq(std::uint64_t refPos, const reference::HashtableConfig::Sequence& s
      ,std::uint32_t varIdx,const Variants& vars, const reference::ReferenceDir7& referenceDir
      , std::string& cigar);
};


}
}
