import sys
T = int(input())


def ask(nums):
	print("? {} {}".format(len(nums), " ".join(str(x) for x in nums)))
	sys.stdout.flush()
	return int(input())


def answer(code):
	print("! {}".format(" ".join(str(x) for x in code)))
	sys.stdout.flush()
	return input()

def union_all(sets):
	out = set()
	for s in sets:
		out.update(s)
	return list(out)


for t in range(T):
	n, k = [int(x) for x in input().strip().split()]

	sets = []
	all_used = set()
	for _ in range(k):
		s = set([int(x) for x in input().strip().split()][1:])
		sets.append(s)
		all_used.update(s)
	rangen = set(range(1, n+1))

	
	m = ask(all_used)

	if k == 1:
		answer([ask(rangen-all_used)])
		continue
	# maxin = ask(all_used)
	# if maxout > maxin:
	# 	assert answer([maxout]*k) == "Correct"
	# 	continue

	l = 0
	u = k-1
	ans = None
	while u>l:
		i = (u+l+1)//2
		s1 = union_all(sets[l:i])
		m1 = ask(s1)

		if m1 >= m:
			m = m1
			u = i-1
		else:
			l = i
		if l == u:
			m3 = ask(rangen-sets[l])
			if m3 >= m:
				ans = [m3]*k
			else:
				ans = [m]*k
				ans[l] = m3

	answer(ans)
