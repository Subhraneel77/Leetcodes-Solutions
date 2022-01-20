const minEatingSpeed = (piles, h) => {
    let max = Math.max(...piles)
    let min = 1
    let bestRes = max

    const getTime = speed => {
        let res = 0
        for (const p of piles)
            res += Math.ceil(p / speed)

        return res
    }

    while (min <= max) {
        let mid = Math.floor((min + max) / 2)
        const tookTime = getTime(mid)

        if (tookTime <= h) {
            bestRes = mid
            max = mid - 1
        } else
            min = mid + 1
    }

    return bestRes
}
