# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generate_random_numbers.py                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 17:17:48 by kkamashi          #+#    #+#              #
#    Updated: 2021/03/21 17:29:02 by kkamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import sys

args = sys.argv
if len(args) != 2:
	sys.exit()

maximum = int(args[1])
randomlist = random.sample(range(0, maximum), maximum)
for num in randomlist:
	print(num, end=" ")