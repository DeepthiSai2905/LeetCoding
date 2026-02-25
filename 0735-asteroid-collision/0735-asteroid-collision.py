class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack: List[int] = []

        for asteroid in asteroids:
            # We'll try to add 'asteroid' to the stack, but it might explode in collisions.
            alive = True

            # While there's a possible collision:
            # stack top moving right (+) and current asteroid moving left (-)
            while alive and stack and stack[-1] > 0 and asteroid < 0:
                top = stack[-1]
                top_size = abs(top)
                curr_size = abs(asteroid)

                if top_size < curr_size:
                    # Top asteroid explodes; current one continues moving and may collide again.
                    stack.pop()
                    # alive stays True, continue loop to check next stack top
                elif top_size == curr_size:
                    # Both explode; remove top and mark current as dead.
                    stack.pop()
                    alive = False
                else:
                    # Current explodes; top remains.
                    alive = False

            # If current asteroid survived all potential collisions, push it.
            if alive:
                stack.append(asteroid)

        return stack
        