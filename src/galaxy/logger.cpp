#include "logger.h"

namespace glxy {
	
void initLogger(const char * const argv)
{
  // FLAGS_log_dir=".";
  FLAGS_alsologtostderr = 1;
  google::InitGoogleLogging(argv);
}

} // namespace glxy
