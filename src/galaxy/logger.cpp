#include "logger.h"

namespace galaxy {
	
void initLogger(const char * const argv)
{
  // FLAGS_log_dir=".";
  FLAGS_alsologtostderr = 1;
  google::InitGoogleLogging(argv);
}

} // namespace galaxy
