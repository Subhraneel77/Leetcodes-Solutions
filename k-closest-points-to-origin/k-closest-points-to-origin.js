
const kClosest = (points = [], K) => {
  const sorted = points.sort(
    ([a, b], [c, d])=> Math.sqrt(a * a + b * b) - Math.sqrt(c * c + d * d),
  )
  return sorted.slice(0, K)
}