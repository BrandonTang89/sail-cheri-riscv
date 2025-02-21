function print_decoded_cap(hi : bits(64), lo : bits(64)) -> unit = {
  print(capToString(bitsToCap(false, hi @ lo)));
  print("\n")
}

function main() -> unit = ()
