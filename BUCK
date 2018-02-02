prebuilt_cxx_library(
  name = 'SDL2',
  header_only = True,
  exported_linker_flags = [
    '-lSDL2',
  ],
)

cxx_binary(
  name = 'game',
  header_namespace = 'graphics',
  headers = subdir_glob([
    ('concept_2/lib', '**/*.hpp'),
  ]),
  srcs = glob([
    'concept_2/src/*.cpp',
    'concept_2/lib/**/*.cpp'
  ]),
  deps = [
    ':SDL2',
  ],
)
